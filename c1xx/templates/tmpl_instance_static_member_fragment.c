void __fastcall
tmpl_instance_static_member_fragment
          (int member,int end,c1_tmpl_work_item *item,char pushed_state,uint explicit_flag,
          int member_link,int member_current,int member_next)

{
  byte bVar1;
  bool bVar2;
  char cVar3;
  uint uVar4;
  void *pvVar5;
  
  if ((*(byte *)(member + 0x1a) & 0x20) == 0) {
    pvVar5 = sym_static_member_stand_in((c1_symbol *)(member + -8));
    if (((*(byte *)((int)pvVar5 + 3) & 4) == 0) && ((*(byte *)((int)pvVar5 + 0x22) & 0x20) == 0)) {
      bVar2 = false;
      uVar4 = explicit_flag >> 8;
      explicit_flag = explicit_flag & 0xffffff00;
      if (((*(byte *)((int)pvVar5 + 0x22) & 0x10) != 0) ||
         (((((item->sym->detail).cls)->flags3e & 0x10) != 0 || (g_opt_BforceInst != '\0')))) {
        *(byte *)((int)pvVar5 + 0x21) = *(byte *)((int)pvVar5 + 0x21) | 0x80;
        *(byte *)(member_current + 0x19) = *(byte *)(member_current + 0x19) | 0x80;
        bVar2 = true;
        explicit_flag = CONCAT31((int3)uVar4,1);
      }
      if (((*(byte *)((int)pvVar5 + 2) & 4) == 0) &&
         ((bVar2 || ((bVar1 = ((item->sym->detail).cls)->flags3e, (bVar1 & 0x20) == 0 &&
                     (((*(byte *)((int)pvVar5 + 0x18) & 3) != 0 || ((bVar1 & 0x10) != 0)))))))) {
        cVar3 = tmpl_instantiate_instance_member
                          (item->sym,(c1_symbol *)(member_current + -8),(char)explicit_flag);
        if (cVar3 != '\0') {
          item->armed = '\x01';
          tmpl_instance_members_loop_fragment
                    (end,item,pushed_state,explicit_flag,member_link,member_next);
          return;
        }
      }
    }
  }
  do {
    member_current = member_next;
    if (member_next == end) {
      if (pushed_state != '\0') {
        decl_state_restore(g_current_scope,'\x01');
        decl_state_pop(g_current_scope);
      }
      return;
    }
    if (member_link == end) {
LAB_104433f8:
      member_next = end;
    }
    else {
      member_link = *(int *)(member_link + 4);
      member_next = member_link;
      if (member_link == end) goto LAB_104433f8;
    }
    uVar4 = class_member_iter_matches((c1_member_iter *)&stack0x00000018);
    if ((((char)uVar4 != '\0') && ((*(byte *)(member_current + -5) & 4) == 0)) &&
       ((*(byte *)(member_current + 0x18) & 7) == 3)) {
      tmpl_instance_static_member_fragment
                (member_current,end,item,pushed_state,explicit_flag,member_link,member_current,
                 member_next);
      return;
    }
  } while( true );
}

