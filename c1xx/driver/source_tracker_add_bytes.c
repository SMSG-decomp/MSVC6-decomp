void __thiscall source_tracker_add_bytes(c1xx_source_tracker *tracker,void *p,int n)

{
  c1_u32 cVar1;
  
  cVar1 = SigForPbCb(p,n,(tracker->iface).signature);
  (tracker->iface).signature = cVar1;
  return;
}

