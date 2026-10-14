c1_u8 __fastcall hash_scope_has_usings(void *scope)

{
  return *(int *)((int)scope + 0x1c) != 0;
}

