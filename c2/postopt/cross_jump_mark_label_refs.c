void __fastcall cross_jump_mark_label_refs(c2_tuple *label,c2_label_ref *stop,uint32_t mark)

{
  c2_tuple *jump;
  c2_label_ref *ref;
  
  for (ref = (c2_label_ref *)label->dst; (ref != (c2_label_ref *)0x0 && (ref != stop));
      ref = ref->next) {
    jump = (c2_tuple *)ref->referrer;
    if ((jump->kind == '\x11') &&
       (((jump->u20).cond_cells == (c2_cond_cell *)0x0 && (jump->op != 0x18b)))) {
      ref->mark = mark;
    }
    else {
      ref->mark = 0xffffffff;
    }
  }
  return;
}

