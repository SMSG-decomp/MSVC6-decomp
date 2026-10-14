byte __thiscall
pdb_open_validated(c1_pdb_state *state,char *name,int *out_signature,int *out_age,long page_size,
                  char *mode)

{
  PDB *pPVar1;
  char cVar2;
  int iVar3;
  SIG SVar4;
  AGE AVar5;
  
  iVar3 = PDBExportValidateInterface(0x13092b6);
  if (iVar3 == 0) {
    diag_fatal_simple(0x386);
  }
  cVar2 = pdbmgr_open(state,name,&state->pdb,'\0',page_size,mode);
  if (cVar2 != '\0') {
    pPVar1 = state->pdb;
    if (pPVar1 == (PDB *)0x0) {
      SVar4 = 0;
    }
    else {
      SVar4 = (*pPVar1->vtbl->QuerySignature)(pPVar1);
    }
    *out_signature = SVar4;
    pPVar1 = state->pdb;
    if (pPVar1 != (PDB *)0x0) {
      AVar5 = (*pPVar1->vtbl->QueryAge)(pPVar1);
      *out_age = AVar5;
      return 1;
    }
    *out_age = 0;
    return 1;
  }
  return 0;
}

