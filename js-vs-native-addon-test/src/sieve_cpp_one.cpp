#include <napi.h>
#include <math.h>
#include <iostream>

Napi::Value Sieve(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  uint32_t max = info[0].As<Napi::Number>().Uint32Value();
  std::vector<bool> sieve(max, true);

  for (uint32_t i = 2; i < sqrt(max); i++) {
    if (sieve[i] == true) {
      for (uint32_t j = pow(i, 2); j < max; j += i) {
        sieve[j] = false;
      }
    }
  }

  size_t next = 0;
  Napi::Array primes = Napi::Array::New(env);
  for (uint32_t i = 0; i < max; i++) {
    if (i <= 1) continue;
    if (sieve[i] == true) {
      primes.Set(next++, i);
    }
  }

  return primes;
}

Napi::Object Init(Napi::Env env, Napi::Object exports) {
  exports.Set("sieve", Napi::Function::New(env, Sieve));
  return exports;
}

NODE_API_MODULE(sieve_sync, Init)
