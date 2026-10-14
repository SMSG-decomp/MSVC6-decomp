int __thiscall decl_default_calling_convention(void *type,byte *type2)

{
  void *pvVar1;
  
  if ((*(ushort *)(type2 + 2) & 0x8000) != 0) {
    if ((g_opt_Gr != '\0') || (g_opt_Gc != '\0')) {
      diag_warning(2,0x60,0x25,0x6a);
    }
    return 1;
  }
  if (((*type2 & 0x8f) == 0x85) &&
     ((((((*(byte *)((int)type + 0x1c) & 7) != 3 &&
         (pvVar1 = *(void **)((int)type + 0x48), pvVar1 != g_name_new)) && (pvVar1 != g_name_delete)
        ) && ((pvVar1 != g_name_array_new && (pvVar1 != g_name_array_delete)))) ||
      (type2 != *(byte **)((int)type + 4))))) {
    return 6;
  }
  if (g_opt_Gr != '\0') {
    return 3;
  }
  if (g_default_stdcall == 0) {
    return (g_opt_Gc != '\0') + 1;
  }
  return 5;
}

