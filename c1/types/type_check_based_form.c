void __thiscall type_check_based_form(c1_type_declarator *declarator,uint *based)

{
  if ((*based & 8) != 0) {
    diag_error(0x1ed);
    declarator->flags30 = declarator->flags30 | 1;
  }
  declarator->modifiers = *based;
  declarator->modifiers2 = based[1];
  return;
}

