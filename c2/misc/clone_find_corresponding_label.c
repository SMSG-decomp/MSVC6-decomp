c2_tuple * __fastcall clone_find_corresponding_label(c2_tuple *stop,c2_tuple *orig,c2_tuple *clone)

{
  for (; (orig != stop && (orig != (c2_tuple *)0x0)); orig = orig->next) {
    clone = clone->next;
  }
  if (clone->kind == '\x1a') {
    return clone;
  }
  ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\tuple.c",0x6ae);
}

