WebAssembly.compileStreaming(fetch("prime.wasm"))      
.then(module => {
  self.postMessage(module);                                       
});