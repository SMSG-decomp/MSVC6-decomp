char * __cdecl decorate_calling_convention(char *out,c1_type *type)

{
  switch((byte)type->flags & 7) {
  case 1:
    *out = 'A';
    return out + 1;
  case 2:
    *out = 'C';
    return out + 1;
  case 3:
    *out = 'I';
    return out + 1;
  default:
    *out = 'L';
    return out + 1;
  case 5:
    *out = 'G';
    return out + 1;
  case 6:
    *out = 'E';
    return out + 1;
  }
}

