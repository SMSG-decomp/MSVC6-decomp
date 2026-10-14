c1_type_declarator * __thiscall decl_new_declarator(c1_type_declarator *declarator,void *name)

{
  c1_u8 cVar1;
  c1_u8 cVar2;
  c1_u8 cVar3;
  int iVar4;
  c1_type_declarator *pcVar5;
  
  pcVar5 = declarator;
  for (iVar4 = 0xe; iVar4 != 0; iVar4 = iVar4 + -1) {
    pcVar5->base = (c1_type *)0x0;
    pcVar5 = (c1_type_declarator *)&pcVar5->first;
  }
  cVar1 = g_empty_specifier_words.inlining;
  cVar2 = g_empty_specifier_words.declspec;
  cVar3 = g_empty_specifier_words.allocate;
  (declarator->spec).storage = g_empty_specifier_words.storage;
  (declarator->spec).inlining = cVar1;
  (declarator->spec).declspec = cVar2;
  (declarator->spec).allocate = cVar3;
  (declarator->spec).segment = g_empty_specifier_words.segment;
  cVar1 = g_empty_specifier_words.pad09[0];
  cVar2 = g_empty_specifier_words.pad09[1];
  cVar3 = g_empty_specifier_words.pad09[2];
  (declarator->spec).flags8 = g_empty_specifier_words.flags8;
  (declarator->spec).pad09[0] = cVar1;
  (declarator->spec).pad09[1] = cVar2;
  (declarator->spec).pad09[2] = cVar3;
  declarator->name = name;
  return declarator;
}

