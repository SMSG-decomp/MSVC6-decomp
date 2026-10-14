void __cdecl type_check_size_known(c1_type *type)

{
  c1_symbol *cls;
  
  if ((type->code & 0x300) != 0) {
    cls = (type->extra).cls;
    if ((cls->flags3 & 4) != 0) {
      return;
    }
    if (((cls->flags2 & 4) == 0) && (tmpl_instantiate_if_needed(cls), (cls->flags2 & 4) == 0)) {
      if (g_opt_Zg == '\0') {
        diag_error(0x1b,cls);
      }
      cls->flags3 = cls->flags3 | 4;
      return;
    }
  }
  diag_error(0x24,type);
  return;
}

