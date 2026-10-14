c1_catchable_type * __cdecl
eh_catchable_type_init(c1_catchable_type *rec,c1_type *type,char no_members)

{
  c1_sym_list *pcVar1;
  byte bVar2;
  c1_type *pcVar3;
  uint uVar4;
  c1_symbol *pcVar5;
  c1_sym_link *pcVar6;
  
  if (rec == (c1_catchable_type *)0x0) {
    return (c1_catchable_type *)0x0;
  }
  if (type == (c1_type *)0x0) {
    rec->type = (c1_type *)0x0;
    rec->type_unref = (c1_type *)0x0;
    rec->flags = 0;
    rec->cls = (c1_symbol *)0x0;
  }
  else {
    rec->type = type;
    bVar2 = (byte)type->code;
    pcVar3 = type;
    if (((char)bVar2 < '\0') && ((bVar2 & 0x8f) == 0x80)) {
      pcVar3 = type->base;
    }
    rec->type_unref = pcVar3;
    uVar4 = type_classify_class_form(type,(int *)&rec->cls);
    rec->flags = uVar4;
  }
  rec->derived = (c1_catchable_type *)0x0;
  rec->this_offset = 0;
  rec->path = (int *)0x0;
  rec->base = (c1_symbol *)0x0;
  if ((rec->flags & 0xd) == 0) {
    rec->flags = 0;
    rec->cls = (c1_symbol *)0x0;
  }
  else {
    if ((no_members == '\0') && ((rec->flags & 9) != 0)) {
      pcVar5 = (c1_symbol *)
               class_find_member_function_matching(type,(int)g_name_ctor,sym_is_copy_constructor);
      rec->copy_ctor = pcVar5;
      if (pcVar5 == (c1_symbol *)0x0) {
        rec->flags = rec->flags & 0xfffffff6 | 0x800;
      }
      pcVar5 = (c1_symbol *)class_find_complete_destructor(type);
      rec->dtor = pcVar5;
      if (pcVar5 == (c1_symbol *)0x0) {
        rec->copy_ctor = (c1_symbol *)0x0;
        rec->flags = rec->flags & 0xfffffff6 | 0x20;
      }
    }
    if (&rec->bases != (c1_member_iter *)0x0) {
      pcVar5 = rec->cls;
      pcVar1 = (pcVar5->x28).members;
      if (pcVar1 == (c1_sym_list *)0x0) {
        pcVar6 = (c1_sym_link *)0x0;
      }
      else {
        pcVar6 = pcVar1->head;
      }
      (rec->bases).cursor.current = pcVar6;
      (rec->bases).cursor.valid = pcVar6 != (c1_sym_link *)0x0;
      (rec->bases).current = (void *)0x0;
      (rec->bases).next = (void *)0x0;
      (rec->bases).cls = &pcVar5->name;
      (rec->bases).filter = 4;
      if (pcVar6 != (c1_sym_link *)0x0) {
        (rec->bases).next = pcVar6;
        return rec;
      }
    }
  }
  return rec;
}

