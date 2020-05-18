<script src="a.out.js"></script>
<script>
  Module.onRuntimeInitialized : {
    const fib = Module.cwrap('fib', 'number', ['number']);
    console.log(fib(12));
  };
</script>