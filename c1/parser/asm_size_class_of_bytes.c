char __cdecl asm_size_class_of_bytes(int size)

{
  if (size < 0xb) {
    switch(size) {
    case 1:
      return '\0';
    case 2:
      return '\x01';
    case 4:
      return '\x02';
    case 6:
      return '\x05';
    case 8:
      return '\x03';
    case 10:
      return '\x04';
    }
  }
  else {
    if (size == 0xffff) {
      return '\x02';
    }
    if (size == 0xfffe) {
      return '\x05';
    }
  }
  return '\x0f';
}

