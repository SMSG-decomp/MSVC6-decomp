int __cdecl type_pointer_attributes_compatible(ushort flags,ushort target_flags)

{
  if (g_opt_Zg != '\0') {
    return 1;
  }
  if (((flags ^ target_flags) & 0x18) == 0) {
    if ((target_flags & 7) == 0) {
      return 1;
    }
    return (uint)(((flags ^ target_flags) & 7) == 0);
  }
  return 0;
}

