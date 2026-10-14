void __fastcall union_find_link(c2_split_uf_cell *a,c2_split_uf_cell *b)

{
  c2_split_uf_cell *pcVar1;
  c2_split_uf_cell *pcVar2;
  
  pcVar2 = a->parent;
  while (pcVar1 = pcVar2, pcVar1 != (c2_split_uf_cell *)0x0) {
    a = pcVar1;
    pcVar2 = pcVar1->parent;
  }
  pcVar2 = b->parent;
  while (pcVar1 = pcVar2, pcVar1 != (c2_split_uf_cell *)0x0) {
    b = pcVar1;
    pcVar2 = pcVar1->parent;
  }
  if (b != a) {
    b->parent = a;
  }
  return;
}

