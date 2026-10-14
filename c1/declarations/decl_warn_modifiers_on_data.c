void __fastcall decl_warn_modifiers_on_data(c1_type_declarator *declarator)

{
  if ((short)declarator->modifiers != 0) {
    diag_warning(1,0xe5);
    declarator->modifiers = 0;
    declarator->modifiers2 = 0;
  }
  return;
}

