# JavaScript vs C++

A simple demonstration of the potential performance differences in plain JavaScript and native addons implemented with N-API. One native addon is an exact copy of the JavaScript algorithm; the other addon implements a small optimization.

Using a recent version of Node.js:

```bash
npm install
npm start
```

On my system, I get the following results:

```
$ node -v
v10.12.0

$ npm start

       JavaScript x 194,031 ops/sec ±2.28% (86 runs sampled)
C++ (plain array) x 40,446 ops/sec ±1.77% (90 runs sampled)
C++ (typed array) x 226,341 ops/sec ±3.70% (77 runs sampled)
```

If you want to change the C++ code to experiment, you'll need to run `npm run build` in order to rebuild the native addon.
