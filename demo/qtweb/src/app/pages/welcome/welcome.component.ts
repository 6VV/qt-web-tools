import { Component, OnInit } from '@angular/core';
import { CppChannelService } from 'src/app/ts-cpp-object/cpp-channel.service';

@Component({
  selector: 'app-welcome',
  templateUrl: './welcome.component.html',
  styleUrls: ['./welcome.component.less']
})
export class WelcomeComponent implements OnInit {

  a: number = 0;
  b: number = 0;
  sum: number = 0;
  msg1="hello";
  msg2="world";

  name: string = '';
  age: number = 0;

  jsCpp: any = null;

  constructor(private qWebChannelService: CppChannelService) { }

  ngOnInit() {
    this.qWebChannelService.getCppObject<JsCpp>("JsCpp").subscribe((jsCpp: JsCpp) => { 
      this.jsCpp = jsCpp;
      this.jsCpp.sigNameChanged.connect((newName:string)=>{
        this.name=newName;
      });
      this.jsCpp.sigAgeChanged.connect((newAge:number)=>{
        this.age=newAge;
      });
    })
  }

  beginSum(): void {
    this.jsCpp.add(1,2,(sum:number)=>{
      this.sum = sum;
      console.log(sum);
    });
  }

  sendMsg():void{
    this.jsCpp.showMsg(this.msg1,this.msg2);
  }
}
