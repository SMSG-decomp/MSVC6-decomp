void __cdecl decl_check_declarator_void_fragment(c1_type_declarator *declarator)

{
  diag_error(0xb6,declarator->sym);
  declarator->flags30 = declarator->flags30 | 1;
  declarator->base = g_type_int;
  if ((((declarator->last->code & 0x8f) == 0x83) && ((declarator->base->code & 0x200) != 0)) &&
     ((((declarator->base->extra).sym)->flags4 & 1) != 0)) {
    diag_error(0xe9,declarator->sym);
    declarator->flags30 = declarator->flags30 | 1;
  }
  declarator->last->base = declarator->base;
  return;
}

