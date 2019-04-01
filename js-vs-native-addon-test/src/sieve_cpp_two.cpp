#include <napi.h>
#include <math.h>
#include <vector>

Napi::Value Sieve(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  uint32_t max = info[0].As<Napi::Number>().Uint32Value();
  uint32_t num_primes = max;
  std::vector<bool> sieve(max, true);

  for (uint32_t i = 2; i < sqrt(max); i++) {
    if (sieve[i] == true) {
      for (uint32_t j = pow(i, 2); j < max; j += i) {
        if (sieve[j] != false) {
          sieve[j] = false;
          num_primes--;
        }
      }
    }
  }

  size_t next = 0;
  Napi::Uint32Array primes = Napi::Uint32Array::New(env, num_primes - 2);
  uint32_t* primes_data = primes.Data();
  for (uint32_t i = 0; i < max; i++) {
    if (i <= 1) continue;
    if (sieve[i] == true) {
      primes_data[next++] = i;
    }
  }

  return primes;
  // Note: converting this TypedArray into a regular array
  // makes it almost exactly as fast as the JS version.
  // return Napi::Array(env, primes);
}

Napi::Object Init(Napi::Env env, Napi::Object exports) {
  exports.Set("sieve", Napi::Function::New(env, Sieve));
  return exports;
}

NODE_API_MODULE(sieve_sync, Init)
