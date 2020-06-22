# Snap Interfaces

## Publishing a Snap
```bash
# Login to your Snapcraft Account
snapcraft login

# Build Snap Package
cd root/of/your/snap
snapcraft

# Publish to Stable Chnnel
snapcraft register snap_name
snapcraft push snap_name.snap --release stable

# Publishing Privately
snapcraft register --private snap_name
snapcraft push snap_name.snap --release stable
```



### References
1. https://forum.snapcraft.io/t/publishing-private-snaps/1905
2. https://forum.snapcraft.io/t/installing-private-snap-package/5816