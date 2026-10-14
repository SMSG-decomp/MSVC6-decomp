void __fastcall
cross_jump_fix_labels
          (c2_tuple *from_before,c2_tuple *from_end,c2_tuple *to_before,c2_tuple *to_end,
          uint32_t mark,int move_markers)

{
  c2_tuple *pcVar1;
  c2_operand *stop;
  c2_tuple *t;
  c2_tuple *pos;
  
  t = from_before->next;
  pos = to_before->next;
joined_r0x107401f4:
  do {
    pcVar1 = t;
    if (t == from_end) {
      return;
    }
    while ((t = pcVar1, t->kind == '\x1a' || (t->op == 0x1bc))) {
      pcVar1 = t->next;
      if (pos->kind == '\x1a') {
        if (t->kind == '\x1a') {
          stop = pos->dst;
          tuple_move_after(pos,t);
          label_retarget_all_refs(t,(c2_node *)pos);
          cross_jump_mark_label_refs(pos,(c2_label_ref *)stop,mark);
        }
        else {
LAB_10740245:
          if (move_markers != 0) goto LAB_1074023a;
        }
      }
      else {
        if (t->kind != '\x1a') goto LAB_10740245;
LAB_1074023a:
        tuple_move_before(pos,t);
      }
    }
    for (; (pos->kind == '\x1a' || (pos->op == 0x1bc)); pos = pos->next) {
      if (pos == to_end) goto joined_r0x107401f4;
    }
    if (pos != to_end) {
      t = t->next;
      pos = pos->next;
    }
  } while( true );
}

