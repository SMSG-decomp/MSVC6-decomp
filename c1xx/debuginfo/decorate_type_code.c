char * __cdecl decorate_type_code(char *out,c1_type *type)

{
  char *pcVar1;
  
  if (((byte)type->code >> 6 & 1) == 0) {
    pcVar1 = decorate_array_type(out,type);
    return pcVar1;
  }
  *out = 'X';
  return out + 1;
}

