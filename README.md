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

## Using Shared Library
snap-a offers the stringsnap library. snap-b utilizes the stringsnap library and builds the stringrunner binary. We will use the content interface for connecting slots and plugs. 

#### Exposing stringsnap library using slot
```bash
slots:
  lib0-1804:
    interface: content
    content: lib0-1804
    source:
      read:
        - $SNAP/lib
```
The lib0-1804 exposes a slot on the content interface which has the capability to read the $SNAP/lib directory.

#### Utilizing the slot using a plug
```bash
plugs:
  lib0-1804:
    interface: content
    content: lib0-1804
    default-provider: stringsnap:lib0-1804
    target: $SNAP/extra-libs
```
Apart from this, we have to set the LD_LIBRARY_PATH for the stringrunner snap so that it can find the required library at the extra-libs folder created.
```bash
apps:
 my-app:
   command: bin/stringrunner
   plugs:
     - lib0-1804
   environment:
       LD_LIBRARY_PATH: $SNAP/extra-libs/lib
```

#### Establishing an Interface connection
By default, for a content interface, if the slots and plugs are coming from snaps from the same publisher, they are automatically connected. For the snaps to have a publisher associated to them, they have to be installed from the Snap Store. 
For manually connecting two snaps:
```bash
sudo snap connect snap1-name:plug-name snap2-name:slot-name
```

## Notes
1. snap_name shouldn't follow the regex `snap*`
2. Library name should follow the regex `lib*.la`
3. While building the dependent snap, the library will be used 


### References
1. https://forum.snapcraft.io/t/publishing-private-snaps/1905
2. https://forum.snapcraft.io/t/installing-private-snap-package/5816