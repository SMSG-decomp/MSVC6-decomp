c1_type_declarator * __thiscall
decl_init_declarator_over_type
          (c1_type_declarator *declarator,c1_type *type,c1_specifier_words *specifiers)

{
  c1_u8 cVar1;
  c1_u8 cVar2;
  c1_u8 cVar3;
  c1_u8 cVar4;
  c1_symbol *pcVar5;
  int iVar6;
  c1_type_declarator *pcVar7;
  
  pcVar7 = declarator;
  for (iVar6 = 0xe; iVar6 != 0; iVar6 = iVar6 + -1) {
    pcVar7->base = (c1_type *)0x0;
    pcVar7 = (c1_type_declarator *)&pcVar7->first;
  }
  pcVar5 = sym_new_declarator_placeholder();
  declarator->sym = pcVar5;
  cVar1 = specifiers->inlining;
  cVar2 = specifiers->declspec;
  cVar3 = specifiers->allocate;
  (declarator->spec).storage = specifiers->storage;
  (declarator->spec).inlining = cVar1;
  (declarator->spec).declspec = cVar2;
  (declarator->spec).allocate = cVar3;
  (declarator->spec).segment = specifiers->segment;
  cVar1 = specifiers->flags8;
  cVar2 = specifiers->pad09[0];
  cVar3 = specifiers->pad09[1];
  cVar4 = specifiers->pad09[2];
  declarator->base = type;
  (declarator->spec).flags8 = cVar1;
  (declarator->spec).pad09[0] = cVar2;
  (declarator->spec).pad09[1] = cVar3;
  (declarator->spec).pad09[2] = cVar4;
  return declarator;
}

