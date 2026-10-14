c1_declarator * __fastcall declarator_set_position(c1_declarator *declarator)

{
  declarator->position = g_token_position;
  return declarator;
}

