c2_eh_state * __fastcall cxx_eh_clone_object_record(c2_eh_state *src)

{
  uint uVar1;
  c2_function *pcVar2;
  int32_t iVar3;
  c2_symbol *pcVar4;
  c2_eh_state *pcVar5;
  c2_eh_state *pcVar6;
  uint kind;
  
  uVar1 = src->flags;
  kind = uVar1 & 0xff;
  pcVar5 = cxx_eh_new_object_record(kind,0,uVar1 >> 9 & 1);
  pcVar6 = src->origin;
  if (src->origin == (c2_eh_state *)0x0) {
    pcVar6 = src;
  }
  pcVar5->origin = pcVar6;
  if ((5 < kind) && (kind < 8)) {
    pcVar5->u1c = src->u1c;
    return pcVar5;
  }
  pcVar2 = src->funclet;
  pcVar5->funclet_label = src->funclet_label;
  pcVar5->funclet = pcVar2;
  pcVar2->funclet_refs = pcVar2->funclet_refs + 1;
  iVar3 = src->walk_refs;
  pcVar5->refs = src->refs;
  pcVar5->walk_refs = iVar3;
  pcVar5->flags = (pcVar5->flags ^ uVar1) & 0x100 ^ pcVar5->flags;
  if ((uVar1 & 0x100) != 0) {
    pcVar4 = src->guard_word;
    pcVar5->guard_bit = src->guard_bit;
    pcVar5->guard_word = pcVar4;
  }
  return pcVar5;
}

