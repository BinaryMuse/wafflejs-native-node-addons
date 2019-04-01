{
  "targets": [
    {
      "target_name": "sieve_cpp_one",
      "include_dirs": [
        "<!@(node -p \"require('node-addon-api').include\")"
      ],
      "dependencies": [
        "<!(node -p \"require('node-addon-api').gyp\")"
      ],
      "defines": [
        'NAPI_DISABLE_CPP_EXCEPTIONS'
      ],
      "sources": [
        "src/sieve_cpp_one.cpp"
      ]
    },
    {
      "target_name": "sieve_cpp_two",
      "include_dirs": [
        "<!@(node -p \"require('node-addon-api').include\")"
      ],
      "dependencies": [
        "<!(node -p \"require('node-addon-api').gyp\")"
      ],
      "defines": [
        'NAPI_DISABLE_CPP_EXCEPTIONS'
      ],
      "sources": [
        "src/sieve_cpp_two.cpp"
      ]
    }
  ]
}
