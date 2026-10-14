void __cdecl debug_type_emit_if_needed(c1_type *type)

{
  char cVar1;
  c1_symbol *tag;
  
  if (g_opt_Zg == '\0') {
    debug_type_index(type);
    cVar1 = (char)type->code;
    while (cVar1 < '\0') {
      type = type->base;
      cVar1 = (char)type->code;
    }
    if (((((type->code & 0x300) != 0) && (tag = (type->extra).sym, tag != (c1_symbol *)0x0)) &&
        ((tag->kind & 0x1f) == 4)) && ((tag->x2c).references == (c1_symbol_cell *)0x0)) {
      debug_type_record_struct_complete(tag);
    }
  }
  return;
}

