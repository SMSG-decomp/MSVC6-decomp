char __thiscall source_tracker_take(c1_source_tracker_iface *iface,uint *signature,int *count)

{
  (**(code **)(iface[-1].mark + 8))();
  *signature = iface->signature;
  *count = iface->count;
  iface->signature = 0xffffffff;
  iface->count = 0;
  return '\x01';
}

