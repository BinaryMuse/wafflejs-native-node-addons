const sieve_js = require('./src/sieve_js')
const sieve_cpp_one = require('bindings')('sieve_cpp_one')
const sieve_cpp_two = require('bindings')('sieve_cpp_two')

const Benchmark = require('benchmark')
const suite = new Benchmark.Suite()

suite.add('       JavaScript', () => {
  sieve_js.sieve(1000)
})
.add('C++ (plain array)', () => {
  sieve_cpp_one.sieve(1000)
})
.add('C++ (typed array)', () => {
  sieve_cpp_two.sieve(1000)
})
.on('cycle', event => {
  console.log(String(event.target))
})
.run()
