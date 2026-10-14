void __cdecl il_emit_global_symbol_debug_types(int *symref)

{
  char cVar1;
  c1_type *type;
  c1_symbol *tag;
  byte bVar2;
  
  bVar2 = *(byte *)(symref + -2) & 0x1f;
  if (((((bVar2 != 7) && (bVar2 != 8)) && (bVar2 != 6)) || ((*(byte *)((int)symref + -7) & 1) != 0))
     && ((((fe_name *)*symref != g_name_unnamed && ((fe_name *)*symref != (fe_name *)0x0)) &&
         (((*(byte *)((int)symref + -5) & 8) == 0 && ((*(byte *)((int)symref + -7) & 0x40) == 0)))))
     ) {
    free_list_push_124c((c1_symbol *)(symref + -2));
    type = (c1_type *)symref[3];
    if (g_opt_Zg == '\0') {
      debug_type_index(type);
      cVar1 = (char)type->code;
      while (cVar1 < '\0') {
        type = type->base;
        cVar1 = (char)type->code;
      }
      if ((((type->code & 0x300) != 0) && (tag = (type->extra).sym, tag != (c1_symbol *)0x0)) &&
         (((tag->kind & 0x1f) == 4 && ((tag->x2c).references == (c1_symbol_cell *)0x0)))) {
        debug_type_record_struct_complete(tag);
      }
    }
    free_list_pop_124c();
  }
  return;
}

