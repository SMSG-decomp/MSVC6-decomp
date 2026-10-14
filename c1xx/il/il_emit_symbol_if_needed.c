void __cdecl il_emit_symbol_if_needed(int *symref)

{
  char cVar1;
  fe_name *pfVar2;
  c1_type *type;
  c1_symbol *sym;
  byte bVar3;
  
  bVar3 = *(byte *)(symref + -2) & 0x1f;
  if (((((bVar3 != 7) && (bVar3 != 8)) && (bVar3 != 6)) || ((*(byte *)((int)symref + -6) & 4) != 0))
     && (((pfVar2 = (fe_name *)*symref, pfVar2 != g_name_unnamed && (pfVar2 != (fe_name *)0x0)) &&
         (((*(byte *)(symref + -1) & 8) == 0 &&
          (((*(byte *)((int)symref + -5) & 1) == 0 || (pfVar2 == g_name_this)))))))) {
    free_list_push_124c((c1_symbol *)(symref + -2));
    type = (c1_type *)symref[3];
    if (g_opt_Zg == '\0') {
      debug_type_index(type);
      cVar1 = (char)type->code;
      while (cVar1 < '\0') {
        type = type->base;
        cVar1 = (char)type->code;
      }
      if (((((type->code & 0x300) != 0) && (sym = (type->extra).cls, sym != (c1_symbol *)0x0)) &&
          ((sym->kind & 0x1f) == 4)) && (((sym->detail).cls)->debug_index == 0)) {
        debug_emit_class_type(sym);
      }
    }
    free_list_pop_124c();
  }
  return;
}

