c1_token * __fastcall decl_parse_declaration_specifiers(c1_specifier_state *spec)

{
  c1_token *pcVar1;
  int iVar2;
  
  iVar2 = 0;
  while( true ) {
    switch((&g_token_class)[spec->token->code]) {
    case 6:
      iVar2 = decl_specifier_try_typedef_name(spec);
      break;
    default:
      iVar2 = 1;
      break;
    case 0x1b:
    case 0x1c:
    case 0x1d:
      iVar2 = decl_check_tag_specifier(spec);
      break;
    case 0x1e:
      decl_specifier_set_type_name(spec);
      break;
    case 0x1f:
      decl_combine_type_specifiers(spec);
      break;
    case 0x20:
      decl_specifiers_add_storage_class(spec);
      break;
    case 0x21:
      decl_specifiers_add_modifier(spec);
      break;
    case 0x22:
      iVar2 = decl_specifier_from_type_token(spec);
      break;
    case 0x28:
      iVar2 = decl_specifier_add_qualifier(spec);
      break;
    case 0xba:
      decl_parse_declspec(&spec->words);
      spec->storage_given = '\x01';
    }
    spec->unk08 = spec->unk08 + 1;
    if (iVar2 != 0) break;
    pcVar1 = token_next(&g_token_position);
    spec->token = pcVar1;
  }
  if (iVar2 != 2) {
    (*g_token_source->stream->vtbl->unget)(g_token_source->stream,spec->token);
    if ((spec->qualifiers != 0) || (spec->named_type == (c1_type *)0x0)) {
      decl_parse_pointer_qualifiers(spec);
    }
    pcVar1 = decl_specifier_token(spec,'$');
    return pcVar1;
  }
  return spec->token;
}

