byte * __cdecl class_find_member_function_matching(c1_type *type,int name,void *predicate)

{
  fe_name **ppfVar1;
  c1_type *pcVar2;
  byte bVar3;
  char cVar4;
  c1_symbol *pcVar5;
  c1_symbol *fn;
  c1_sym_link *link;
  c1_sym_link *next_link;
  c1_symbol *pcVar6;
  
  cVar4 = (char)type->code;
  while (cVar4 < '\0') {
    type = type->base;
    cVar4 = (char)type->code;
  }
  pcVar5 = class_find_member_function((type->extra).cls,(void *)name);
  if (pcVar5 == (c1_symbol *)0x0) {
    return (byte *)0x0;
  }
  ppfVar1 = &pcVar5->name;
  pcVar6 = (c1_symbol *)0x0;
  if (ppfVar1 == (fe_name **)0x0) {
    return (byte *)0x0;
  }
  bVar3 = pcVar5->kind & 0x1f;
  pcVar2 = (c1_type *)ppfVar1;
  if ((((bVar3 != 7) && (bVar3 != 8)) && (bVar3 != 6)) && ((pcVar5->kind & 0x1f) != 0x1a)) {
    pcVar2 = pcVar5->type;
  }
LAB_10442ce9:
  link = (c1_sym_link *)pcVar2;
  if (ppfVar1 == (fe_name **)0x0) {
    return &pcVar6->kind;
  }
  if (link == (c1_sym_link *)0x0) {
    return &pcVar6->kind;
  }
  bVar3 = pcVar5->kind & 0x1f;
  if (((bVar3 == 7) || (bVar3 == 8)) || ((bVar3 == 6 || ((pcVar5->kind & 0x1f) == 0x1a)))) {
    next_link = (c1_sym_link *)0x0;
  }
  else {
    next_link = link->next;
  }
  if (predicate != (void *)0x0) goto LAB_10442d24;
  goto LAB_10442d0e;
LAB_10442d24:
  fn = (c1_symbol *)&link[-1].position;
  if ((link[-1].position & 0x1f) == 0x1a) {
    fn = ((link->type).alias)->target;
  }
  cVar4 = (*predicate)(fn);
  pcVar2 = (c1_type *)next_link;
  if (cVar4 != '\0') {
LAB_10442d0e:
    pcVar6 = (c1_symbol *)&link[-1].position;
    pcVar2 = (c1_type *)next_link;
    if ((link[-1].position & 0x1f) == 0x1a) {
      pcVar6 = ((link->type).alias)->target;
      pcVar2 = (c1_type *)next_link;
    }
  }
  goto LAB_10442ce9;
}

