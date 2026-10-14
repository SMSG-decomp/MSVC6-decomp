byte * __cdecl decorate_pointer_code_unsigned_letter(byte letter,c1_type *type,byte *out)

{
  if ((type->code & 0x2000) != 0) {
    letter = letter | 1;
  }
  *out = letter;
  return out + 1;
}

