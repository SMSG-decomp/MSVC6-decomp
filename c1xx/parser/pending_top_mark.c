void __cdecl pending_top_mark(void)

{
  if (((PTR_104d2cb8 != (c1_vector *)0x0) && (PTR_104d2cb8->count != 0)) &&
     (PTR_104d2cb8->data[PTR_104d2cb8->count - 1] != (void *)0x0)) {
    *(undefined1 *)((int)PTR_104d2cb8->data[PTR_104d2cb8->count - 1] + 0x14) = 1;
  }
  return;
}

