void __fastcall
tmpl_instance_members_loop_fragment
          (int end,c1_tmpl_work_item *item,char pushed_state,uint explicit_flag,int member_link,
          int member_next)

{
  uint uVar1;
  void *member;
  
  do {
    member = (void *)member_next;
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
    uVar1 = class_member_iter_matches((c1_member_iter *)&stack0x00000018);
    if ((((char)uVar1 != '\0') && ((*(byte *)((int)member + -5) & 4) == 0)) &&
       ((*(byte *)((int)member + 0x18) & 7) == 3)) {
      tmpl_instance_static_member_fragment
                ((int)member,end,item,pushed_state,explicit_flag,member_link,(int)member,member_next
                );
      return;
    }
  } while( true );
}

