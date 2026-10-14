int __cdecl mre_class_ensure_records(c1_symbol *cls)

{
  c1_class_record *pcVar1;
  char cVar2;
  
  if ((((cls->name != g_name_unnamed) && ((cls->flags2 & 4) != 0)) &&
      (pcVar1 = (cls->detail).cls, (pcVar1->flags3e & 0x40) == 0)) &&
     ((g_debug_types_in_pdb == '\0' || ((pcVar1->flags3f & 8) == 0)))) {
    if (pcVar1->gm_name_index == 0) {
      cVar2 = mre_class_name_index(cls);
      if (cVar2 == '\0') {
        return 2;
      }
    }
    if ((cls->type->debug_index == 0) || (((cls->detail).cls)->debug_index == 0)) {
      debug_emit_class_type(cls);
    }
    return 0;
  }
  return 1;
}

