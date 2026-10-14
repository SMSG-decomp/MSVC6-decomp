uint __fastcall decl_dll_linkage_kind(void *spec)

{
  return ((*(byte *)((int)spec + 2) & 8) >> 3) << 1 | *(byte *)((int)spec + 2) >> 2 & 1;
}

