int __fastcall cross_jump_label_refs(c2_tuple *label)

{
  c2_tuple *j2;
  int iVar1;
  c2_label_ref *ref;
  c2_label_ref *later_ref;
  uint mark;
  int changed;
  int anchor_gone;
  c2_tuple *jump;
  
  mark = 0;
  for (ref = (c2_label_ref *)label->dst; ref != (c2_label_ref *)0x0; ref = ref->next) {
    jump = (c2_tuple *)ref->referrer;
    if (((jump->kind == '\x11') && ((jump->u20).cond_cells == (c2_cond_cell *)0x0)) &&
       (jump->op != 0x18b)) {
      ref->mark = 0;
      *(undefined2 *)((int)&ref->referrer[1].next + 2) = 0;
    }
    else {
      ref->mark = 0xffffffff;
    }
  }
  changed = 0;
LAB_1073d0fa:
  ref = (c2_label_ref *)label->dst;
  while( true ) {
    if (ref == (c2_label_ref *)0x0) {
      return changed;
    }
    if (ref->mark != 0xffffffff) break;
    ref = ref->next;
  }
  j2 = (c2_tuple *)ref->referrer;
  mark = mark + 1;
LAB_1073d125:
  later_ref = ref->next;
  do {
    if (later_ref == (c2_label_ref *)0x0) {
      ref->mark = 0xffffffff;
      goto LAB_1073d0fa;
    }
    if (later_ref->mark < mark) {
      iVar1 = cross_jump_pair((c2_tuple *)later_ref->referrer,j2,mark,&anchor_gone);
      if (iVar1 != 0) break;
      later_ref->mark = mark;
    }
    later_ref = later_ref->next;
  } while( true );
  changed = 1;
  if (anchor_gone != 0) goto LAB_1073d0fa;
  goto LAB_1073d125;
}

