void __thiscall decl_apply_specifiers(c1_type_declarator *declarator,c1_decl_specifiers *spec)

{
  c1_u8 cVar1;
  c1_u8 cVar2;
  c1_u8 cVar3;
  
  if (declarator->base == (c1_type *)0x0) {
    declarator->base = spec->type;
  }
  cVar1 = (spec->words).inlining;
  cVar2 = (spec->words).declspec;
  cVar3 = (spec->words).allocate;
  (declarator->spec).storage = (spec->words).storage;
  (declarator->spec).inlining = cVar1;
  (declarator->spec).declspec = cVar2;
  (declarator->spec).allocate = cVar3;
  (declarator->spec).segment = (spec->words).segment;
  cVar1 = (spec->words).pad09[0];
  cVar2 = (spec->words).pad09[1];
  cVar3 = (spec->words).pad09[2];
  (declarator->spec).flags8 = (spec->words).flags8;
  (declarator->spec).pad09[0] = cVar1;
  (declarator->spec).pad09[1] = cVar2;
  (declarator->spec).pad09[2] = cVar3;
  return;
}

