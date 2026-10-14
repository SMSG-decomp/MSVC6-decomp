void __fastcall decl_check_conversion_syntax(void *d)

{
  if (((((*(byte *)((int)d + 0x3c) & 8) == 0) && (*(int *)((int)d + 4) != 0)) ||
      (*(short *)((int)d + 0xc) != 0)) || (*(int *)((int)d + 4) != *(int *)((int)d + 8))) {
    diag_error(0x24a);
    *(byte *)((int)d + 0x3c) = *(byte *)((int)d + 0x3c) | 1;
  }
  return;
}

