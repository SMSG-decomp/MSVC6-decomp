uint __cdecl type_merge_qualifiers(uint first,uint second)

{
  if ((first & second & 0x3e0) != 0) {
    if (g_ms_extensions == '\0') {
      diag_error(0x121);
    }
    else {
      diag_warning(1,0x72);
    }
  }
  if (((((first ^ second) & 0x18) != 0) && ((first & 8) != 0)) && ((second & 8) != 0)) {
    diag_error(0x121);
  }
  if (((((first ^ second) & 7) != 0) && ((first & 7) != 0)) && ((second & 7) != 0)) {
    diag_error(0x97);
    first = first & 0xfff8;
  }
  return first | second;
}

