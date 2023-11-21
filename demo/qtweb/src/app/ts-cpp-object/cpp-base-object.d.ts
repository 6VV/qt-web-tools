/*************************
 * Base Object
*************************/
declare interface QtSignal<T> {
    connect(fun: T): void;
    disconnect(fun: T): void;
}

declare interface QtObject {
    deleteLater(): void;
    destroyed: QtSignal<(obj: QtObject) => void>;
    objectNameChanged: QtSignal<(objName: string) => void>;
}
