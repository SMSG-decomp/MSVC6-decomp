void * __thiscall pdb_ipm_elem48_vector_deleting_dtor(fe_idb_include_state *elements,byte flags)

{
  fe_idb_region *pfVar1;
  int iVar2;
  fe_idb_include_state *pfVar3;
  
  if ((flags & 2) == 0) {
    pfVar1 = (elements->regions).data;
    if (pfVar1 != (fe_idb_region *)0x0) {
      __3_YAXPAX_Z(pfVar1);
    }
    if ((flags & 1) != 0) {
      __3_YAXPAX_Z(elements);
    }
    return elements;
  }
  iVar2 = *(int *)&elements[-1].changed;
  pfVar3 = elements + iVar2;
  if (-1 < iVar2 + -1) {
    do {
      pfVar1 = pfVar3[-1].regions.data;
      pfVar3 = pfVar3 + -1;
      if (pfVar1 != (fe_idb_region *)0x0) {
        __3_YAXPAX_Z(pfVar1);
      }
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  if ((flags & 1) != 0) {
    __3_YAXPAX_Z(&elements[-1].changed);
  }
  return &elements[-1].changed;
}

