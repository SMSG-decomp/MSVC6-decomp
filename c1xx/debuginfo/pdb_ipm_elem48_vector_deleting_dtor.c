void * __thiscall pdb_ipm_elem48_vector_deleting_dtor(c1_idb_include_state *states,byte flags)

{
  c1_idb_region *pcVar1;
  int iVar2;
  c1_idb_include_state *pcVar3;
  
  if ((flags & 2) == 0) {
    pcVar1 = (states->regions).data;
    if (pcVar1 != (c1_idb_region *)0x0) {
      __3_YAXPAX_Z(pcVar1);
    }
    if ((flags & 1) != 0) {
      __3_YAXPAX_Z(states);
    }
    return states;
  }
  iVar2 = *(int *)&states[-1].changed;
  pcVar3 = states + iVar2;
  if (-1 < iVar2 + -1) {
    do {
      pcVar1 = pcVar3[-1].regions.data;
      pcVar3 = pcVar3 + -1;
      if (pcVar1 != (c1_idb_region *)0x0) {
        __3_YAXPAX_Z(pcVar1);
      }
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  if ((flags & 1) != 0) {
    __3_YAXPAX_Z(&states[-1].changed);
  }
  return &states[-1].changed;
}

