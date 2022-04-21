import { Injectable } from '@angular/core';
import { EventEmitter } from 'events';
import { Observable, Observer } from 'rxjs';
import { QWebChannel } from './qwebchannel';

@Injectable({
  providedIn: 'root'
})
export class CppChannelService {

  private socket: WebSocket;
  private cppObjects: any = {};
  private event: EventEmitter = new EventEmitter();

  constructor() {
    this.socket = new WebSocket('ws://localhost:12345');

    this.socket.onclose = () => {
      console.error("web channel closed");
    };
    this.socket.onerror = (ev: Event) => {
      console.error("web channel error: " + ev);
    };
    this.socket.onopen = () => {
      console.log("WebSocket connected, setting up QWebChannel.");
      new QWebChannel(this.socket, (channel: any) => {
        console.log(channel);
        this.cppObjects = channel.objects;
        this.event.emit("channelChanged");
      });
    }
  }

  public getCppObject<T>(key: string): Observable<T> {
    return new Observable((observer: Observer<T>) => {
      let channelChangedEvent = () => {
        if ((this.cppObjects as Object).hasOwnProperty(key)) {
          observer.next(this.cppObjects[key]);
          this.event.off('channelChanged', channelChangedEvent);
        }
      };
      this.event.on('channelChanged', channelChangedEvent);

      channelChangedEvent();
      return () => {
        this.event.off('channelChanged', channelChangedEvent);
      }
    });
  }
}
