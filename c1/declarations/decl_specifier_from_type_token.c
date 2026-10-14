int __fastcall decl_specifier_from_type_token(c1_specifier_state *spec)

{
  c1_token *pcVar1;
  c1_u32 cVar2;
  
  if (spec->unk08 == 0) {
    pcVar1 = spec->token;
    spec->type_given = '\x01';
    spec->named_type = (pcVar1->value).spec.type;
    spec->named = (pcVar1->value).spec.named;
    spec->tag_insert = (void *)0x0;
    spec->qualifiers = spec->named_type->flags;
    *(void **)&spec->words = (pcVar1->value).ptr;
    (spec->words).segment = (void *)(pcVar1->value).words[1];
    cVar2 = (pcVar1->value).words[2];
    (spec->words).flags8 = (char)cVar2;
    (spec->words).pad09[0] = (char)(cVar2 >> 8);
    (spec->words).pad09[1] = (char)(cVar2 >> 0x10);
    (spec->words).pad09[2] = (char)(cVar2 >> 0x18);
    return 0;
  }
  return 1;
}

