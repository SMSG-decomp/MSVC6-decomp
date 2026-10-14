byte * __thiscall class_find_member_function_walk_overloads(c1_symbol *cls,void *name,void *pred)

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
  
  pcVar5 = class_find_member_function(cls,name);
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
LAB_10440401:
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
  if (pred != (void *)0x0) goto LAB_10478868;
  goto LAB_1044042a;
LAB_10478868:
  fn = (c1_symbol *)&link[-1].position;
  if ((link[-1].position & 0x1f) == 0x1a) {
    fn = ((link->type).alias)->target;
  }
  cVar4 = (*pred)(fn);
  pcVar2 = (c1_type *)next_link;
  if (cVar4 != '\0') {
LAB_1044042a:
    pcVar6 = (c1_symbol *)&link[-1].position;
    pcVar2 = (c1_type *)next_link;
    if ((link[-1].position & 0x1f) == 0x1a) {
      pcVar6 = ((link->type).alias)->target;
      pcVar2 = (c1_type *)next_link;
    }
  }
  goto LAB_10440401;
}

