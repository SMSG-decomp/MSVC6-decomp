int __thiscall decl_function_flags_compatible(void *self,ushort flags1,ushort flags2,int unused)

{
  if (flags1 != flags2) {
    if (((flags1 ^ flags2) & 0x1f) != 0) {
      return 0;
    }
    if (((flags1 ^ flags2) & 0x3e0) != 0) {
      return 0;
    }
    if (((flags1 & 0x18) != 0) && ((flags2 & 0x18) != 0)) {
      return 0;
    }
  }
  return 1;
}

