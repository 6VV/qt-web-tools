/**
 * CppObject
 */

 declare interface JsRouter extends QtObject{
    sigNavigateByUrl: QtSignal<(value: string) => void>;
    navigateInitUrl(): void;
}

declare interface JsCpp extends QtObject {
    showMsg(msg1: string, msg2: string): void;
    add(a: number, b: number, fun: (sum: number) => void): void;
    sigNameChanged: QtSignal<(value: string) => void>;
    sigAgeChanged: QtSignal<(value: number) => void>;
}

