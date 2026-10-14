c1_symbol * __thiscall scope_stack_lookup_anonymous_member(c1_scope_stack *scopes,void *name)

{
  char cVar1;
  c1xx_scope *pcVar2;
  c1_type *pcVar3;
  byte bVar4;
  bool bVar5;
  c1_symbol *local_4;
  
  local_4 = (c1_symbol *)0x0;
  bVar4 = scopes->depth;
  do {
    pcVar2 = scopes->contexts[bVar4];
    if (pcVar2->kind < 0xfb) {
LAB_10493dae:
      (*pcVar2->vtbl->lookup_anonymous_member)(name,&local_4);
    }
    else {
      pcVar3 = ((pcVar2->body).cls)->type;
      cVar1 = (char)pcVar3->code;
      while (cVar1 < '\0') {
        pcVar3 = pcVar3->base;
        cVar1 = (char)pcVar3->code;
      }
      if ((pcVar3->code & 0x100) == 0) goto LAB_10493dae;
    }
    bVar5 = bVar4 == 0;
    bVar4 = bVar4 - 1;
    if (bVar5) {
      return local_4;
    }
  } while( true );
}

