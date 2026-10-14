void __cdecl debug_type_emit_if_needed(c1_type *type)

{
  char cVar1;
  c1_symbol *sym;
  
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
  return;
}

