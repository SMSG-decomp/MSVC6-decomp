uint32_t __fastcall label_is_removable(c2_tuple *t)

{
  if ((t->src[1].rank & 0x10000) == 0) {
    switch(*(undefined1 *)&t->src[1].next) {
    case 0:
      break;
    default:
      return 0;
    case 5:
    case 6:
    case 7:
    case 0xc:
      return g_label_merge_class1;
    }
  }
  return 1;
}

